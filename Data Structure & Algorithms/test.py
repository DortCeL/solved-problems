import tkinter as tk
import math


def draw_binary_tree(canvas, arr):
    canvas.delete("all")  # Clear previous drawings

    if not arr:
        canvas.create_text(300, 50, text="The tree is empty!",
                           font=("Arial", 16), fill="red")
        return

    n = len(arr)
    levels = math.ceil(math.log2(n + 1))  # Number of levels in the tree

    canvas_width = 600
    canvas_height = 400
    node_radius = 20

    for level in range(levels):
        # Start and end indices of elements at this level
        start_index = 2 ** level - 1
        end_index = min(2 ** (level + 1) - 1, n)

        # X spacing between nodes at this level
        x_spacing = canvas_width // (2 ** (level + 1))
        y_position = 50 + level * 70  # Y position for this level

        for i in range(start_index, end_index):
            x_position = (2 * (i - start_index) + 1) * x_spacing

            # Draw node
            canvas.create_oval(
                x_position - node_radius, y_position - node_radius,
                x_position + node_radius, y_position + node_radius,
                fill="lightblue"
            )
            canvas.create_text(
                x_position, y_position, text=str(arr[i]), font=("Arial", 12), fill="black"
            )

            # Draw lines to children
            left_child = 2 * i + 1
            right_child = 2 * i + 2

            if left_child < n:
                left_x = (2 * (left_child - start_index) + 1) * x_spacing
                canvas.create_line(
                    x_position, y_position + node_radius,
                    left_x, y_position + 70 - node_radius,
                    fill="black"
                )
            if right_child < n:
                right_x = (2 * (right_child - start_index) + 1) * x_spacing
                canvas.create_line(
                    x_position, y_position + node_radius,
                    right_x, y_position + 70 - node_radius,
                    fill="black"
                )


def on_show_tree():
    try:
        arr = list(map(int, entry.get().split(',')))
        draw_binary_tree(canvas, arr)
    except ValueError:
        canvas.delete("all")
        canvas.create_text(300, 50, text="Invalid input! Enter integers separated by commas.", font=(
            "Arial", 16), fill="red")


# Tkinter window setup
root = tk.Tk()
root.title("Binary Tree Visualization")

frame = tk.Frame(root)
frame.pack()

# Input field for array
tk.Label(frame, text="Enter array elements (comma-separated):").pack(side=tk.LEFT, padx=5)
entry = tk.Entry(frame, width=30)
entry.pack(side=tk.LEFT, padx=5)
tk.Button(frame, text="Show Tree", command=on_show_tree).pack(
    side=tk.LEFT, padx=5)

# Canvas to draw the tree
canvas = tk.Canvas(root, width=600, height=400, bg="white")
canvas.pack()

root.mainloop()
