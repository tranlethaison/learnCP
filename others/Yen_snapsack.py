""" Yen's Knapsack Problem
Given a set of items each with weight & value, and a knapsack with capacity.
Find the maximum value of subset items that can fit into that snapsack.
  values = [120,420,610,112,341,435,657,363,273,812,534,356,223,516]
  weights = [20,40,60,12,34,45,67,33,23,12,34,56,23,56]
  capacity = 150

A. By Dynamic Programing:
Let call:
  Wi, Vi: weight, value of item i.
  n: #items.
  C: capacity.
  X: remaining capacity. (X <= N)

5 steps to DP:
  1. Define subproblem, count #subproblems.
    - Subproblem: Suffix [i:] of items.
    - #subproblems = n * C

  2. Guess (part of solution), count #guesses.
    - Guessing: Is item i in subset or not?
    - #guesses = n

  3. Recurrence. Calculate time/subproblem.
    - Recurrence: dp(i, X) = max(dp(i + 1, X), dp(i + 1, X - Wi) + Vi)
    - Time/subproblem: O(1)
    - Time: O(n * C)

  4. Recuse + Memorize; Or Bottom-up. (remember to check acylic)
  5. Solve original problem.

  * Time = #subproblems * time/subproblem
"""