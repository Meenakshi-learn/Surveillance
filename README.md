SurvSim: Smart Surveillance System Simulator v1.3

Author: Meenakshi
Version: 1.2 — 5th December 2025
**Technologies:** C Programming (Modular Design, Enums, Function Pointers, Callback Functions, Stack, File Handling, Input Safety)

A fully modular C-based console simulation representing the backend of an AI-driven surveillance system — now with alert stacks, enums, and callback handlers.

---

## 🎯 Objective

To simulate real-world surveillance backend behavior using advanced C programming concepts such as structures, enums, stacks, safe input, file logging, and callback-based alert handlers.

---

main.c            — Menu system + alert mode switching
camera.c          — Camera adding, status display, location validation
detection.c       — Motion detection, stack push, callback execution
summary.c         — System-wide summary
logger.c          — Log writing + log viewing
input.c           — Safe input functions (strings, ints)
survsim.h         — All structs, enums, globals & prototypes
surv_log.txt      — Auto-generated log file

---

 gcc main.c camera.c detection.c summary.c logger.c input.c stack.c -o survsim && ./survsim

---

## 🧠 Key Features (v1.4)

### ✔ 1. Camera Management
- Add and manage multiple cameras (up to 5)
- Cameras now use **status enums**:
  - `CAMERA_ACTIVE`
  - `CAMERA_INACTIVE`
- Motion state managed using enums:
  - `MOTION_CLEAR`
  - `MOTION_DETECTED`

### ✔ 2. Predefined Valid Camera Locations
- Only allows selecting from a defined environment:
  - Entrance  
  - LivingRoom  
  - Kitchen  
  - Hallway  
  - Garage  
  - Backyard  
- User cannot enter garbage or unsupported locations

### ✔ 3. Safe Input System (No Crashes!)
- `safeReadInt()` to avoid scanf crashes  
- `safeReadString()` for protected string input  
- `clearInputBuffer()` to handle bad inputs  
- Prevents infinite loops and invalid menu choices  

### ✔ 4. Logging System (Persistent Storage)
- Logs every alert with a timestamp
- Stores logs in `surv_log.txt`
- Added `showLog()` to display logs directly in terminal

### ✔ 5. Callback-Based Alert Modes (Function Pointers)
SurvSim now supports **runtime selectable alert behaviors**:

- **Default Alert**
- **Loud Alert (simulated siren)**
- **Silent Alert (stealth mode)**

All handled using:

```c
typedef void (*AlertCallback)(Camera *cam);

And implemented in:

defaultAlertHandler()
loudAlertHandler()
silentAlertHandler()
User can switch alert mode from the menu.