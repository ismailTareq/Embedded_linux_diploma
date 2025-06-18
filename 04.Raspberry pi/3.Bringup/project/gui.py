import tkinter as tk
import pandas as pd
from datetime import datetime

class CSVViewer:
    def __init__(self, root):
        self.root = root
        self.root.title("Sensor Data Viewer")
        
        self.label_temp = tk.Label(root, text="Average Temperature: --", font=('Arial', 14))
        self.label_temp.pack(pady=10)
        
        self.label_humid = tk.Label(root, text="Average Humidity: --", font=('Arial', 14))
        self.label_humid.pack(pady=10)
        
        self.update_button = tk.Button(root, text="Update Data", command=self.update_data)
        self.update_button.pack(pady=20)

    def update_data(self):
        try:
            df = pd.read_csv("sensor_data.csv")
            avg_temp = df['Temperature'].mean()
            avg_humid = df['Humidity'].mean()
            
            self.label_temp.config(text=f"Average Temperature: {avg_temp:.1f}°C")
            self.label_humid.config(text=f"Average Humidity: {avg_humid:.1f}%")
        except Exception as e:
            self.label_temp.config(text=f"Error: {str(e)}")
            self.label_humid.config(text="")

if __name__ == "__main__":
    root = tk.Tk()
    app = CSVViewer(root)
    root.mainloop()
