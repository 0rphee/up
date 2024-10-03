module Main where

import Debug.Trace (traceShowId)

{-
    se puede correr el código en https://play.haskell.org/
    o para instalar el compilador de haskell y correrlo: https://www.haskell.org/ghcup/
    > runghc algoritmo1.hs
-}

euclidesMCD :: Int -> Int -> Maybe Int
euclidesMCD a b
  | a == 0 || b == 0 = Nothing
  | otherwise = Just $! go (abs a) (abs b)
  where
    go c1 d1
      | d1 == 0 = abs c1
      | otherwise =
          let !r = c1 `mod` d1
              !c2 = d1
              !d2 = r
           in go c2 d2

main :: IO ()
main = do
  let f !a !b = do
        let !res = euclidesMCD a b
        putStrLn $ mconcat ["mcd(", show a, ", ", show b, ") = ", show res]
  f 10 10 -- mcd(10, 10) = Just 10
  f 20 2 -- mcd(20, 2) = Just 2
  f 30 7 -- mcd(30, 7) = Just 1
  f 15 10 -- mcd(15, 10) = Just 5
  f 143 52 -- mcd(143, 52) = Just 13
  f 3 0 -- mcd(3, 0) = Nothing
  f 0 3 -- mcd(0, 3) = Nothing

-- El código siguiente no correrá en https://play.haskell.org/
-- debido al input, pero si se puede ejecutar localmente
-- (debe tener la misma indentación que las líneas previas).

-- putStrLn "\nEscribe el primer número: "
-- a <- read <$> getLine
-- putStrLn "Escribe el segundo número: "
-- b <- read <$> getLine
-- f a b
