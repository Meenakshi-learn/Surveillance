# SurvSim v1.1 — Smart Surveillance System Simulator

## 🎯 Overview
SurvSim is a C-based simulation of a smart AI surveillance backend.
It demonstrates how a real camera-based monitoring system tracks cameras,
detects motion, and raises alerts — before integrating with YOLO and Jetson hardware.

## 🧩 Features
- Add up to 5 simulated cameras
- Track motion detection per camera
- Persistent state using static memory
- Summary of total alerts and cameras
- Structured modular C code design

## 🧠 Concepts Used
- Data types, arrays, loops, decision-making
- Structures and pointers
- Storage classes (`static`, `register`)
- Functions and modular programming
- Boolean logic and state management

## ⚙️ Compile and Run
```bash
gcc main.c -o SurvSim
./SurvSim
