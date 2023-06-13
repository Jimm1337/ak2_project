import signal
import time
from serial import Serial
from getch import getch


# This is where the log file is created
def get_file_name(formatted_date):
    return "/home/pi/ak2_projekt/logs/" + formatted_date + ".txt"


# Write to output_stream (serial) and log file
def log(character, formatted_date, output_stream):
    # Write to tty the char code of the key pressed
    print("Char code: " + str(ord(character)))
    output_stream.write(character.encode())

    # Should use match but stuck in python 3.9
    if ord(character) == 31:  # CTRL + ? or CTRL + - to quit
        exit()
    elif ord(character) == 13:  # Enter
        character = "\n"
    elif ord(character) == 127:  # Backspace
        character = "<Backspace\\>"
    elif ord(character) == 215:  # Right arrow
        character = "<RightArrow\\>"
    elif ord(character) == 216:  # Left arrow
        character = "<LeftArrow\\>"
    elif ord(character) == 217:  # Down arrow
        character = "<DownArrow\\>"
    elif ord(character) == 218:  # Up arrow
        character = "<UpArrow\\>"

    with open(get_file_name(formatted_date), "a+") as logging_file:
        logging_file.write(character)


# convert arrow codes to something we can send
def convert_arrow(code):
    # should use match but stuck in python 3.9
    if ord(code) == 65:
        return 218
    elif ord(code) == 66:
        return 217
    elif ord(code) == 67:
        return 215
    elif ord(code) == 68:
        return 216
    else:
        return 0


if __name__ == "__main__":
    serial = Serial("/dev/ttyS0", 9600, timeout=2)

    date = time.strftime("%c").replace(" ", "-")
    print("Logging started at: " + date)

    with open(get_file_name(date), "w+") as output_file:
        output_file.write("Started at " + date + "\n")

    # Handle CTRL + Z (just do nothing instead of quitting)
    signal.signal(signal.SIGTSTP, lambda signum, frame: ())

    while True:
        try:
            first_read = getch()
            if ord(first_read) == 27:
                second_read = getch()
                if ord(second_read) == 91:  # Arrows emit 27, 91 and then the arrow code
                    arrow_code = getch()
                    arrow = chr(convert_arrow(arrow_code))
                    log(arrow, date, serial)
                else:  # Other sequences beginning with 27
                    log(first_read, date, serial)
                    log(second_read, date, serial)
            else:  # Other sequences not beginning with 27
                log(first_read, date, serial)
        except KeyboardInterrupt:
            log(chr(3), date, serial)
        except OverflowError:
            pass
