def min_bad_segments(n, x, prices):
  """
  Calculates the minimum number of bad segments for n cards with prices and a forbidden product value x.

  Args:
      n: The number of cards (prices).
      x: The forbidden product value.
      prices: A list of integers representing the prices on the cards.

  Returns:
      The minimum number of bad segments.
  """
  current_segment = 1
  for price in prices:
    if gcd(price, x) > 1:  # Check if price has common divisor with x (using GCD function)
      current_segment += 1
  return current_segment

# Function to calculate Greatest Common Divisor (GCD)
def gcd(a, b):
  """
  Calculates the greatest common divisor of two integers.

  Args:
      a: The first integer.
      b: The second integer.

  Returns:
      The greatest common divisor of a and b.
  """
  while b != 0:
    a, b = b, a % b
  return a

def main():
  """
  Reads input, solves test cases, and prints output.
  """
  t = int(input())  # Read number of test cases
  for _ in range(t):
    n, x = map(int, input().split())  # Read n and x
    prices = list(map(int, input().split()))  # Read prices
    min_segments = min_bad_segments(n, x, prices)
    print(min_segments)  # Print minimum number of bad segments for this test case

if __name__ == "__main__":
  main()
