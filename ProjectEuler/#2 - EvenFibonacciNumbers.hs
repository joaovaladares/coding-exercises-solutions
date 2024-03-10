module EvenFibonnaciNumbers where

-- Find the sum of all even Fibonacci numbers below 4 million.
-- First idea 
fibs :: [Integer]
fibs = 1 : 2 : zipWith (+) fibs (tail fibs)

sumEvenFibNumbersBelow4m :: Integer
sumEvenFibNumbersBelow4m = sum $ filter even $ takeWhile (< 4000000) fibs

-- Second idea
sumEvenFibNumbersBelow4m' :: Integer 
sumEvenFibNumbersBelow4m' = sum [x | x <- takeWhile (< 4000000) fibs, even x]
