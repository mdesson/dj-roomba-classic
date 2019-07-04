import serial

# (very) temporarily Windows only
arduino = serial.Serial('COM3', 9600)


def main():
    while True:
        cmd = input('Enter 0 or 1 to toggle LED, or q to quit: ')
        if cmd == 'q':
            break
        elif cmd == '1' or cmd == '0':
            arduino.write(cmd.encode())
        else:
            print('Invalid input')


if __name__ == '__main__':
    main()
