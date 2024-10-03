{-# LANGUAGE MultiWayIf #-}

module Main where

{-
    se puede correr el código en https://play.haskell.org/
    para instalar el compilador de haskell y correrlo: https://www.haskell.org/ghcup/
    > runghc algoritmo1.hs
-}

{- | integer division:
@divi 10 1 = Just (0, 10)@
@divi 10 100 = Just (10, 0)@
@divi 10 0 = Nothing@
-}
divi
  :: Int
  -- ^  a
  -> Int
  -- ^ b
  -> Maybe (Int, Int)
  -- ^ Maybe (remainder, quotient)
divi a b
  | b == 0 = Nothing
  | a == 0 = Just (0, 0)
  | otherwise =
      Just $!
        let (!r, !q) = go (abs a) 0
         in if
              | a > 0 -> (r, q)
              | r == 0 -> (0, -q)
              | otherwise -> (b - r ,-q - 1)
  where
    go !r !q
      | r >= b = go (r - b) (q + 1)
      | otherwise = (r, q)

main :: IO ()
main = do
  let f !a !b = do
        let res = divi a b
        putStrLn $ mconcat [show a, " // ", show b, " = ", show res]

  f 10 20

  f 20 2

  f 30 7

-- El código siguiente no correrá en https://play.haskell.org/
-- debido al input, pero si se puede ejecutar localmente
-- (debe tener la misma indentación que las líneas previas).

-- putStrLn "\nEscribe el dividendo: "
-- a <- read <$> getLine
-- putStrLn "Escribe el divisor: "
-- b <- read <$> getLine
-- f a b
