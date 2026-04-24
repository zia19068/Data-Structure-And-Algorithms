<div align="center">

<br>

```
██████╗ ███████╗ █████╗     ██╗      ██████╗ ██╗  ██╗███████╗
██╔══██╗██╔════╝██╔══██╗    ██║     ██╔═══██╗██║  ██║██╔════╝
██║  ██║███████╗███████║    ██║     ██║   ██║███████║███████╗
██║  ██║╚════██║██╔══██║    ██║     ██║   ██║██╔══██║╚════██║
██████╔╝███████║██║  ██║    ███████╗╚██████╔╝██║  ██║███████║
╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚══════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝
```

### Data Structures & Algorithms in C++

*Ground-up implementations. No STL. No shortcuts. Just pointers.*

<br>

[![Language](https://img.shields.io/badge/C%2B%2B-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![No STL](https://img.shields.io/badge/STL-Not%20Used-EF4444?style=for-the-badge)]()
[![Commits](https://img.shields.io/badge/Commits-72-6366F1?style=for-the-badge&logo=git&logoColor=white)](https://github.com/zia19068/Data-Structure-And-Algorithms/commits/main)
[![License](https://img.shields.io/badge/License-MIT-22C55E?style=for-the-badge)](LICENSE)

<br>

</div>

---

## ✦ About This Repository

This repository contains **hand-crafted C++ implementations** of every major data structure and algorithm taught in a Computer Science DSA course — built entirely without the Standard Template Library.

Every line is written to expose the *internals*: raw memory allocation, manual pointer manipulation, and explicit object lifecycle management. If you've ever wondered what `std::stack` looks like under the hood, you're in the right place.

```
📁 DSA Concepts/          ←  Core implementations & theory
📁 Lab Practice Problems/ ←  Applied exercises & problem solving
```

---

## 🧠 OOP & Memory Foundations

Before any structure can be safely implemented, these fundamentals are mastered:

| Concept | What It Covers |
|---|---|
| **Abstract Data Types** | Hiding implementation behind clean public interfaces |
| **Heap Allocation** | Manual `new` / `delete` — no RAII shortcuts |
| **Rule of Three** | Destructor · Copy Constructor · Assignment Operator |
| **Deep vs Shallow Copy** | Preventing dangling pointers & double-free errors |

> ⚠️ The **Rule of Three** is the backbone of every class in this repo — any object that owns heap memory correctly implements all three.

---

## 📦 Linear Data Structures

### 🔗 Linked Lists

```
Singly:    [A] → [B] → [C] → NULL
Doubly:    [A] ⇌ [B] ⇌ [C] → NULL
Circular:  [A] → [B] → [C] ──┐
            └─────────────────┘
```

### 📚 Stack — LIFO

```cpp
push(x)   // Insert at top
pop()     // Remove from top
top()     // Peek without removing
```
Implemented with both **arrays** and **linked lists**.

### 🚦 Queue — FIFO

| Type | Mechanism |
|---|---|
| **Linear Queue** | Insert at rear, remove at front |
| **Circular Queue** | `rear = (rear + 1) % SIZE` — zero wasted slots |

---

## 🌳 Binary Search Tree

```
           [50]
          /    \
       [30]    [70]
       /  \    /  \
    [20] [40][60] [80]
```

| Operation | Description |
|---|---|
| **Insert** | Recursive placement: left if smaller, right if larger |
| **Search** | O(log n) path traversal |
| **Delete** | Handles leaf nodes, one child, and two children cases |
| **Inorder** | Produces sorted ascending output ✓ |
| **Preorder** | Root → Left → Right |
| **Postorder** | Left → Right → Root |

---

## ⚡ Sorting Algorithms

| Algorithm | Time (Best) | Time (Avg) | Time (Worst) | Space | Technique |
|---|:---:|:---:|:---:|:---:|---|
| **Bubble Sort** | O(n) | O(n²) | O(n²) | O(1) | Adjacent swaps |
| **Selection Sort** | O(n²) | O(n²) | O(n²) | O(1) | Find minimum, move front |
| **Insertion Sort** | O(n) | O(n²) | O(n²) | O(1) | Build sorted left portion |
| **Merge Sort** | O(n log n) | O(n log n) | O(n log n) | O(n) | Divide & conquer |
| **Quick Sort** | O(n log n) | O(n log n) | O(n²) | O(log n) | Pivot partitioning |
| **Comb Sort** | O(n log n) | O(n²/2ᵖ) | O(n²) | O(1) | Gap shrink factor 1.3 |

> 💡 **Comb Sort** is Bubble Sort with a twist — large gaps eliminate *turtles* (small values stuck near the end) long before they become a problem.

---

## 🔍 Searching Algorithms

| Algorithm | Complexity | Prerequisite | Technique |
|---|:---:|---|---|
| **Linear Search** | O(n) | None | Scan every element |
| **Binary Search** | O(log n) | Sorted array | Halve the search space |
| **Interpolation Search** | O(log log n) | Sorted + uniform | Estimate position by value |

**Interpolation formula:**
```
pos = low + [ (target - arr[low]) × (high - low) ] / (arr[high] - arr[low])
```

---

## 🔄 Expression Conversion

| Conversion | Tool Used | Key Rule |
|---|---|---|
| **Infix → Postfix** | Operator stack | Respect PEMDAS precedence |
| **Postfix → Infix** | Operand stack | Wrap each operation in parentheses |

```
Infix:    ( A + B ) * ( C - D )
Postfix:    A B + C D - *
```

---

## 🗂️ Repository Layout

```
📦 Data-Structure-And-Algorithms/
│
├── 📁 DSA Concepts/
│   ├── Linked Lists/       (Singly, Doubly, Circular)
│   ├── Stack/              (Array-based & Node-based)
│   ├── Queue/              (Linear & Circular)
│   ├── BST/                (Insert, Search, Delete, Traversals)
│   ├── Sorting/            (Bubble, Selection, Insertion, Merge, Quick, Comb)
│   ├── Searching/          (Linear, Binary, Interpolation)
│   └── Expressions/        (Infix to Postfix, Postfix to Infix)
│
└── 📁 Lab Practice Problems/
    └── (Applied exercises & exam-style problems)
```

---

## 🚀 Getting Started

```bash
# 1. Clone the repo
git clone https://github.com/zia19068/Data-Structure-And-Algorithms.git
cd Data-Structure-And-Algorithms

# 2. Navigate to any concept
cd "DSA Concepts"

# 3. Compile with g++
g++ -std=c++17 -Wall your_file.cpp -o output

# 4. Run
./output
```

**Requirements:** Any C++17-compatible compiler — `g++`, `clang++`, or MSVC.

---

## 📌 Key Design Decisions

- ✅ **No STL** — `std::vector`, `std::stack`, `std::queue` deliberately avoided
- ✅ **Manual memory** — every `new` has a matching `delete`
- ✅ **Recursive logic** — BST operations use clean recursive implementations
- ✅ **Modular files** — each concept lives in its own file for clarity

---

## 👤 Author

**Zia** — [@zia19068](https://github.com/zia19068)

---

<div align="center">

*Built one segfault at a time.*

If this helped you, consider leaving a ⭐ — it means a lot!

</div>
