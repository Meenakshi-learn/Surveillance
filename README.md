SurvSim: Smart Surveillance System Simulator v1.3

Author: Meenakshi
Version: 1.3 — 21st November 2025
Technologies: C Programming (Modular Design, File Handling, Safe Input, Validation)

A C-based console simulation that models the backend logic of an AI-powered surveillance system.

🎯 Objective

Extend SurvSim v1.2 with environment-based camera location validation and improved user experience, making the system behave like a real surveillance configuration tool.

🧠 Features

Add and manage multiple cameras

Choose from predefined valid camera locations (NEW)

Reject invalid or garbage locations

Simulate motion detection events

Trigger alerts on detection

Log each alert with timestamps

View the log file directly in the terminal

Safe input system (no crashes / infinite loops)

Modular multi-file architecture

Display live system summary

🧩 Concepts Demonstrated

✅ Arrays

✅ Loops

✅ Structures (typedef)

✅ Pointers

✅ Functions

✅ File Handling

✅ Input Validation

✅ Error Handling

✅ Storage Classes

✅ Modular Programming

📍 Predefined Valid Camera Locations (v1.3)

The system only accepts these camera locations:

Entrance
LivingRoom
Kitchen
Hallway
Garage
Backyard


Any other value is rejected until the user provides a valid one.