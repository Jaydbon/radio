import pygetwindow as gw
import serial

title = ''
temp = ''
titleParts = ''

ard = serial.Serial('COM4', baudrate=9600)

while True:
    
    # Format Titles to send to radio
    temp = titleParts
    window = gw.getWindowsWithTitle("VLC media player")[0]
    title = window.title
    title = title.replace(' - VLC media player', '')
    titleParts = title.split('- ')
    
    
    if titleParts != temp: # Make Sure Title is Changed
        toSend = ""
        for thing in titleParts:
            toSend = toSend + "-" + thing
        toSend = toSend[1:]
        ard.write(bytes(str(toSend + '\n'), 'utf-8'))
        print(toSend)