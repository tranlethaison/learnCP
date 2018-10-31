"""Yen's Knapsack Problem
Given a set of items each with weight & value, and a knapsack with capacity.
Find the maximum value of subset items that can fit into that knapsack.
  values = [120,420,610,112,341,435,657,363,273,812,534,356,223,516]
  weights = [20,40,60,12,34,45,67,33,23,12,34,56,23,56]
  capacity = 150

Let's call:
  Wi, Vi: weight, value of item i.
  n: #items.
  C: capacity.

5 steps of Dynamic Programing:
  1. Define subproblem.
    - Suffix i: of items. `items[i:]`

  2. Guessing.
    - Is item `i` in max-value subset or not?

  3. Recurrence (relate subproblems to each other); aka Try all guesses & Take the best.
    - Max-value when:
      + Item `i` is not in subset is:
        max-value of `items[i+1:]`

      + Item `i` is in subset is:
        `Vi` plus max-value of `items[i+1:]`. Capacity is now decreased by `Wi`.

    - Let's call `X` the remaining capacity (X <= C). We have:
      f(i, X) = max(f(i + 1, X), f(i + 1, X - Wi) + Vi)

  4. Do Recuse & Memorize; Or Bottom-up. Remember to check for acyclic.
    - Base case: Ran out of items to include, or remaining capacity is 0.
    - Please see code below.

  5. Calculate complexity.
    Overall Time = #subproblems * time/subproblem
                 = O(n * C) * O(1)
                 = O(n * C)

"""

class Knapsack:
  def __init__(self, W, V):
    assert len(W) == len(V)
    self.W = W # Weights
    self.V = V # Values
    self.n = len(W) # #items


  def init_memory(self, C):
    """Store calculated recursion values to reuse.
    """
    self.M = [
      [-1 for _ in range(C + 1)]
      for __ in range(self.n + 1)
    ]


  def res(self, i, X):
    """Recurse & memorize
    """
    # If recursion value is in memory, reuse it.
    if self.M[i][X] != -1:
      return self.M[i][X]

    # Otherwise, calculate & store.
    if i == self.n or X == 0:
      f = 0
    elif X >= self.W[i]:
      f = max(
        self.res(i + 1, X),
        self.res(i + 1, X - self.W[i]) + self.V[i]
      )
    else:
     f = self.res(i + 1, X)

    self.M[i][X] = f
    return f


  def bup(self, C):
    """Bottom Up
    """
    F = [
      [-1 for _ in range(C + 1)]
      for __ in range(self.n + 1)
    ]

    for i in range(self.n, -1, -1):
      for X in range(C + 1):
        if i == self.n or X == 0:
          F[i][X] = 0
        elif X >= self.W[i]:
          F[i][X] = max(
            F[i + 1][X],
            F[i + 1][X - W[i]] + self.V[i]
          )
        else:
         F[i][X] = F[i + 1][X]

    return F[0][C]


if __name__ == "__main__":
  V = [120,420,610,112,341,435,657,363,273,812,534,356,223,516]
  W = [20,40,60,12,34,45,67,33,23,12,34,56,23,56]
  C = 150

  # V = list(map(int, "20 16 45 73 99 87 38 53 99 99 38 65 22 17 17 51".split(' ')))
  # W = list(map(int, "31 21 78 53 18 66 61 4 11 65 16 99 87 91 44 23".split(' ')))
  # C = 98
  # expected = 356

  # V = list(map(int, "55 61 51 75 17 22 4 13 39 28 77 49 46 91 14 67 88 62 25 37 69 38 59 62 48 88 100 53".split(' ')))
  # W = list(map(int, "96 16 34 53 88 6 50 26 76 10 8 4 37 18 73 54 30 31 97 2 28 24 2 30 79 77 33 86".split(' ')))
  # C = 83
  # expected = 474

  # Recurse & Memorize
  K = Knapsack(W, V)
  K.init_memory(C)
  out = K.res(0, C)
  print(out)

  # Bottom Up
  K2 = Knapsack(W, V)
  out = K2.bup(C)
  print(out)