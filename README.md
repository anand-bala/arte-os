arte-os
=======

Another Real-Time Embedded OS

## What is arte-os

**arte-os** is my attempt at learning to design a real-time and embedded operating system.
The goal is to make a completely modular, light-weight and fast real-time OS.


## Structure

* `core/` : This directory will contain all core features including hardware peripheral interface, threads, the scheduler, and synchronization primitives
* `modules/` : This directory will contain any extra modules. The exact meaning of a module is open-ended and left for discussion.
* `user/` : This directory is where any user of the RTOS can place application specific source code.

