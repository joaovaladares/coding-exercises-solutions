module MultiplesOf3Or5Below1000 where

-- Find the sum of all numbers below 1000 that are multiples of 3 or 5.

-- Using Lambda
multiplesOf3Or5Below1000 :: Integer
multiplesOf3Or5Below1000 = sum $ filter (\x -> x `mod` 3 == 0 || x `mod` 5 == 0) [1..999]

-- Using list comprehension
multiplesOf3Or5Below1000' :: Integer
multiplesOf3Or5Below1000' = sum [x | x <- [1..999], x `mod` 3 == 0 || x `mod` 5 == 0]
