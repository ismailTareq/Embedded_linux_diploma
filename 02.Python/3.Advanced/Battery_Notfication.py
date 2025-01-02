from pynotifier import Notification
import psutil

battery = psutil.sensors_battery()
percent = battery.percent

print(percent)

Notification(title="Battery Status", description=f"{percent:.2f}% Percent remaining", duration=10)