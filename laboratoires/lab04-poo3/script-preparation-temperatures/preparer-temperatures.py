import csv
from datetime import datetime
import pytz

data = []
with open('./history.csv', newline='', encoding='utf-8') as csvfile:
    reader = csv.reader(csvfile)
    for row in [row for row in reader][1:]:
        _, temperature_str, timestamp_utc = row
        temperature = float(temperature_str)
        datetime_obj = datetime.fromisoformat(timestamp_utc)
        timestamp = datetime_obj.astimezone(pytz.timezone('America/Montreal')).strftime('%Y-%m-%dT%H:%M:%S')
        data.append((temperature, timestamp))

with open('temperatures.txt', 'w', encoding='utf-8') as f:
    for temperature, timestamp in data:
        f.write(f"{timestamp} {temperature}\n")
