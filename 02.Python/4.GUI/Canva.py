import tkinter as tk
import math

class Gauge(tk.Canvas):
    def __init__(self, master, size=200, *args, **kwargs):
        super().__init__(master, width=size, height=size, *args, **kwargs)
        self.size = size
        self.configure(bg='white', highlightthickness=0)
        self.draw_gauge()

    def draw_gauge(self):
        center = self.size // 2
        radius = center - 10

        # Draw outer circle
        self.create_oval(10, 10, self.size - 10, self.size - 10, outline='black', width=2)
        
        angle = 135  
        value = 0.4  
        angle_offset = 270  # Offset the gauge position
        indicator_angle = angle_offset + (value * 270)

        x1 = center + radius * math.cos(math.radians(angle_offset))
        y1 = center + radius * math.sin(math.radians(angle_offset))
        x2 = center + radius * math.cos(math.radians(indicator_angle))
        y2 = center + radius * math.sin(math.radians(indicator_angle))
        self.create_line(center, center, x2, y2, fill='red', width=3)

        # Draw center circle
        self.create_oval(center - 10, center - 10, center + 10, center + 10, fill='black')

        # Display value
        self.create_text(center, center + 30, text=f'{int(value * 100)}%', font=('Arial', 14), fill='black')

if __name__ == "__main__":
    root = tk.Tk()
    root.title("Gauge Example")

    gauge = Gauge(root)
    gauge.pack(pady=20)

    root.mainloop()