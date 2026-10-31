import serial
import csv
import time
from datetime import datetime

# --- CONFIGURATION ---
# Replace with your actual port (e.g., 'COM3' on Windows, '/dev/cu.usbmodem...' on macOS)
SERIAL_PORT = 'COM4' 
BAUD_RATE = 9600
CSV_FILE = 'temperatures.csv'

print(f"Connecting to Arduino on {SERIAL_PORT}...")

try:
  # Initialize serial connection
  ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
  time.sleep(2) # Give Arduino time to reset/initialize
  print("Connected successfully! Logging data... Press Ctrl+C to stop.")

  # Open/create CSV file and write header if it's empty
  with open(CSV_FILE, mode='a', newline='') as file:
    writer = csv.writer(file)
    if file.tell() == 0:
      writer.writerow(["Timestamp", "Temperature (C)", "Humidity (%)"])

    while True:
      if ser.in_waiting > 0:
        # Read a line of serial data, decode bytes to string, remove whitespace
        line = ser.readline().decode('utf-8').strip()
        
        # Skip error logs or non-data lines
        if "ERROR" in line or not line:
          print(f"Status: {line}")
          continue
          
        try:
          # Parse comma-separated text: "24.5,60.0" -> ["24.5", "60.0"]
          temp, humidity = line.split(',')
          current_time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
          
          # Append to file
          writer.writerow([current_time, temp, humidity])
          file.flush() # Force write to disk immediately
          
          print(f"[{current_time}] Saved -> Temp: {temp}°C | Humidity: {humidity}%")
          
        except ValueError:
          print(f"Raw parsing skip (Non-CSV line): {line}")

except serial.SerialException:
  print(f"Error: Could not open serial port {SERIAL_PORT}. Is it plugged in or used by Arduino IDE?")
except KeyboardInterrupt:
  print("\nLogging stopped by user. Goodbye!")
