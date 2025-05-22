# 🖼️ Filter_C – CS50 Image Filter Tool

Filter_C is a C-based image processing program developed as part of Harvard’s CS50 course. It applies image filters—grayscale, sepia, reflect, and blur—to 24-bit uncompressed BMP image files using custom logic.

## ✨ Features

- ✅ Grayscale conversion
- 🟤 Sepia filter with capped RGB intensity
- 🔁 Horizontal reflection of image
- 💨 Box blur effect
- 📁 Reads and writes BMP files (24-bit uncompressed)
- 🧪 Error handling for invalid filters and file I/O

## 🧠 How It Works

This program accepts a filter flag and two filenames: an input BMP and an output BMP. It loads the image into memory, applies the selected filter, and writes the new image to disk.

```bash
./filter -s input.bmp output.bmp
```

Available filter flags:
-g : Grayscale
-s : Sepia
-r : Reflect
-b : Blur

---

## 🛠️ Compilation
You can compile the project using make:
```
make filter
```
This will create an executable called filter.

---

## 📂 Project Structure
```
Filter_C/
├── filter.c              # Main CLI program
├── helpers.c             # Filter implementations
├── helpers.h             # Function prototypes
├── Makefile              # Build script
├── images/
│   ├── before.bmp        # Sample input
│   └── after.bmp         # Output placeholder
```

---

## 👨‍💻 Author

**Burhan Mustafa**  
📫 [burhanmustafa808@gmail.com](mailto:burhanmustafa808@gmail.com)  
🌐 [LinkedIn](https://www.linkedin.com/in/burhan-mustafa-15899319a/)
🧠 Built with love and late-night debugging.

---

## 🏷️ License

MIT License. Feel free to use, remix, or build on it — just give credit.
