import sys
import datetime

dt = datetime.datetime.now()
mon = 12 - dt.month
day = 25 - dt.day
hr = 23 - dt.hour
mn = 60 - dt.minute
sec = 60 - dt.second

s = repr(day) + 'days\n' + repr(hr) + 'hours\n' + repr(mn) + 'mins\n' + repr(sec) + 'secs\n' + 'X-mas'
print s
text_file = open("Countdown.txt", "w")
text_file.write(s)
text_file.close()
