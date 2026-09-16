# Lua Matatu Terminus Scheduler

## Group 1

### Group Members
1. **FRANKLINE ANTONY TUMAINI** — C026-01-0984/2025
2. **LEVY JUMA** — C026-01-0977/2025
3. **Vessly Clement** — C026-01-0938/2025

## System Description

The Lua Matatu Terminus Scheduler simulates the operation of several matatu routes at a terminus. Each route has its own coroutine, allowing the scheduler to cooperatively switch between routes in a round-robin manner.

The system models passengers boarding, passengers waiting, departure conditions, route state changes, and coroutine-based scheduling.

## Routes

The system contains four routes:

- Rongai
- Thika
- Ngong
- Kitengela

Each route maintains the number of passengers currently on the matatu and the number of waiting events.

## How the System Works

1. Route information is stored in a Lua table.
2. A coroutine is created for every route using `coroutine.create`.
3. The scheduler selects routes in round-robin order.
4. If a route has fewer than 5 passengers, the scheduler sends a `board` command.
5. Otherwise, it sends a `wait` command.
6. The route coroutine receives the command after `coroutine.resume`.
7. `board` increases the passenger count and resets the waiting count.
8. `wait` increases the waiting count.
9. A matatu departs when it has at least 8 passengers, or when waiting exceeds 3 events while the matatu has at least 5 passengers.
10. After departure, passenger and waiting counts are reset.
11. The scheduler continues for 40 cycles.
12. Final route states are displayed.

## Departure Rules

A route departs when either condition is true:

```text
Passengers >= 8
OR
Waiting > 3 AND Passengers >= 5
```

After departure:

```text
Passengers = 0
Waiting = 0
```

## Coroutines

The program demonstrates Lua cooperative concurrency using:

- `coroutine.create()` — creates a coroutine.
- `coroutine.resume()` — starts or continues a coroutine.
- `coroutine.yield()` — pauses the coroutine and returns control to the scheduler.
- `coroutine.status()` — a coroutine state can be inspected when needed.

The coroutine repeatedly waits at `coroutine.yield()` for the scheduler to send a command.

## Round-Robin Scheduler

The scheduler maintains `currentRoute` and moves through the four routes in sequence:

```text
Rongai → Thika → Ngong → Kitengela → Rongai → ...
```

This gives each route an opportunity to perform its next operation.

## Cooperative Concurrency

The program demonstrates cooperative concurrency rather than pre-emptive threading. A route coroutine yields control voluntarily, and the scheduler resumes the selected route.

## Error Handling

`coroutine.resume()` returns a success value and an error message. The scheduler checks the success value and reports an error if a coroutine fails.

## Programming Language

**Lua**

## Programming Language Concepts Demonstrated

- Coroutines
- Cooperative concurrency
- `coroutine.create`
- `coroutine.resume`
- `coroutine.yield`
- Tables
- Functions
- Loops
- Conditional statements
- State management
- Round-robin scheduling
- Error handling
- Event simulation

## Running the Program

Using a Lua interpreter:

```bash
lua main.lua
```

It can also be run using an online Lua compiler such as OneCompiler.

## Expected Behaviour

The scheduler repeatedly processes the four routes. As passengers board and waiting events accumulate, routes reach the departure conditions. The program prints departure events and finally displays the remaining state of each route.
