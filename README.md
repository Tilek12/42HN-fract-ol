# :desktop_computer: 42Heilbronn :de:

<p align="center">
  <img src="https://github.com/Tilek12/42-project-badges/blob/main/badges/fract-olm.png">
</p>

<h1 align="center">
  Project - Fract-ol :milky_way:
  <h2 align="center">
    :white_check_mark: 125/125
  </h2>
</h1>


## :clipboard: Project info: [subject](https://github.com/Tilek12/42HN-fract-ol/blob/master/.git_docs_fract-ol/en.subject_fract-ol.pdf)

The term **fractal** was first used by mathematician Benoit Mandelbrot in 1974. He based it on the Latin word fractus which means "broken" or "fractured".

A **fractal** is an abstract mathematical object, like a curve or a surface, which pattern remains the same at every scale.


## :green_circle: Mandatory Part

**Program name**     | fractol
:---                 |:---
**Turn in files**    | Makefile, *.h, *.c
**Makefile**         | NAME, all, clean, fclean, re
**Arguments**        | The type of fractal to display and any other option available
**External functs.** | • open, close, read, write, malloc, free, perror, strerror, exit
|                    | • All functions of the math library (-lm compiler option, man man 3 math)
|                    | • All functions of the MiniLibX
|                    | • ft_printf and any equivalent YOU coded
**Libft authorized** | Yes
**Description**      | This project is about creating a small fractal exploration program. First, you have to know what a fractal is.

### :eight_spoked_asterisk: V.1 Rendering
- Your program must offer the **Julia** set and the **Mandelbrot** set.
- The mouse wheel zooms in and out, almost infinitely (within the limits of the computer). This is the very principle of fractals.
- You must be able to create different Julia sets by passing different parameters to the program.
- A parameter is passed on the command line to define what type of fractal will be displayed in a window.
  - You can handle more parameters to use them as rendering options.
  - If no parameter is provided, or if the parameter is invalid, the program displays a list of available parameters and exits properly.
- You must use at least a few **colors** to show the depth of each fractal. It’s even better if you hack away on psychedelic effects.

### :eight_spoked_asterisk: V.2 Graphic management
- Your program has to display the image in a window.
- The management of your window must remain smooth (changing to another window, minimizing, and so forth).
- Pressing **ESC** must close the window and quit the program in a clean way.
- Clicking on the cross on the window’s frame must close the window and quit the program in a clean way.
- The use of the **images** of the **MiniLibX** is mandatory.

---

## :star: Bonus part

You will get some extra points with the following features:
- One more different fractal (more than a hundred different types of fractals are referenced online).
- The zoom follows the actual mouse position.
- In addition to the zoom: moving the view by pressing the arrows keys.
- Make the color range shift.

---

## :large_blue_circle: Graphics library

This project is based on [MLX42](https://github.com/codam-coding-college/MLX42) library.

MLX42 (an alternative of the MiniLibX) is a simple cross-platform graphics library running on GLFW and OpenGL.

After running the program, with starting Makefile, the MLX42 library will be downloaded from it's original github repository and will be installed in lib/mlx42 directory.

---

## :red_circle: Control

:keyboard: **Keyboard control:**

Keyboard buttons          | Definition
:---                      |:---
:arrow_up: Arrow up       | Shift the image up
:arrow_down: Arrow down   | Shift the image down
:arrow_left: Arrow left   | Shift the image left
:arrow_right: Arrow right | Shift the image right
:heavy_minus_sign: Minus  | Increase the number of iterations. Make the image sharper by filling it with more pixels per point.
:heavy_plus_sign: Plus    | Decrease the number of iterations.  Make the image less sharp by filling it with less pixels per point.
**"O"**                   | Actavate the **"Original"** mode - image with usual colors
**"P"**                   | Actavate the **"Psychedelic"** mode - image with psychedelic colors
**"L"**                   | Actavate the **"Mutable"** mode (for **Julia** set only) - create different Julia sets according to coordinates of the mouse cursor. Clicking the **"L"** buton again switch this mode off.
**"ESC"**                 | Exit the program

:computer_mouse: **Mouse control:**

Mouse wheel | Definition
:---        |:---
Scroll up   | Zoom in the image
Scroll down | Zoom out the image

---

## :purple_circle: Fractal - Mandelbrot Set

<p align="center">
  <img src="https://github.com/Tilek12/42HN-fract-ol/blob/master/.git_docs_fract-ol/Mandelbrot_o.png">
  <img src="https://github.com/Tilek12/42HN-fract-ol/blob/master/.git_docs_fract-ol/Mandelbrot_p.png">
</p>

---

## :purple_circle: Fractal - Julia Set
  
<h3 align="center">
  Julia Set [+0.285, +0.01]
  <p align="center">
    <img src="https://github.com/Tilek12/42HN-fract-ol/blob/master/.git_docs_fract-ol/Julia_set_1_o.png">
    <img src="https://github.com/Tilek12/42HN-fract-ol/blob/master/.git_docs_fract-ol/Julia_set_1_p.png">
  </p>
</h3>
<h3 align="center">
  Julia Set [-0.8, +0.156]
  <p align="center">
    <img src="https://github.com/Tilek12/42HN-fract-ol/blob/master/.git_docs_fract-ol/Julia_set_2_o.png">
    <img src="https://github.com/Tilek12/42HN-fract-ol/blob/master/.git_docs_fract-ol/Julia_set_2_p.png">
  </p>
</h3>

---

## :purple_circle: Fractal - Tricorn

<p align="center">
  <img src="https://github.com/Tilek12/42HN-fract-ol/blob/master/.git_docs_fract-ol/Tricorn_o.png">
</p>
<p align="center">
  <img src="https://github.com/Tilek12/42HN-fract-ol/blob/master/.git_docs_fract-ol/Tricorn_p.png">
</p>

---

## :purple_circle: Fractal - Burning Ship

<p align="center">
  <img src="https://github.com/Tilek12/42HN-fract-ol/blob/master/.git_docs_fract-ol/Burning_ship_o.png">
</p>
<p align="center">
  <img src="https://github.com/Tilek12/42HN-fract-ol/blob/master/.git_docs_fract-ol/Burning_ship_p.png">
</p>
