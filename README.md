*This project has been created as part of the 42 curriculum by mtakiyos*

# Philosophers

This project, inspired by the famous "Dining Philosophers Problem" introduces the fundamental concepts of concurrent programming using threads. Philosophers explores how to create and manage threads, mutexes for synchronization. Understanding critical concepts like deadlocks and dataraces and how o avoid them was necessary to succesfully develop this project.

### What is Dining Philosophers Problem?

The Dining Philosophers Problem is a fundamental synchronization problem often used in concurrent algorithm design to illustrate synchronization issues and techniques for resolving them. In this problem, a number of philosophers sit at a round table with a bowl of spaghetti in the center. Between each pair of philosophers is a single fork. Each philosopher alternates between eating, sleeping and thinking:

- **Eating**: The philosopher is required to have a fork in each hand to be allowed to eat.
- **Sleeping**: After eating, the philosopher rests
- **Thinking**: The philosopher contemplates life if there are no forks available for him to eat.

### Usage

```bash

./philo  number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philo_must_eat]

```
---

## 📄 Description

Green textLorem Ipsum 

is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.

---
## 📝 Instructions

Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.

---
## 👾 Execution

Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.

---
## 📁 Files 

Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.

---
```bash
philosophers/
├── 📁 include/              # Project (.h) Header
│   └── *.h
│
├── 📁 sources/              # Main files
│   ├── actions.c            # Stores actions
│   ├── inits.c              # Initializes variables used by the project
│   ├── main.c               # Main file
│   ├── monitor.c            # Monitors philosophers' states (eating, thinking, sleeping, dead)
│   ├── parsing.c            # Controls given inputs
│   ├── runtime.c            # Routine
│   ├── utils.c              # Utilitary functions
│   └── state.c              # Stores philosophers' states
│
├── 🧩 Makefile              # Compilation script
└── 📘 README.md             # Project documentation
```
---

## Resources


---
## How AI was used in this project