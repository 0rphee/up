module Main (main) where

import Debug.Trace (traceShowId)

{-
    se puede correr el código en https://play.haskell.org/
    o para instalar el compilador de haskell y correrlo: https://www.haskell.org/ghcup/
    > runghc algoritmo1.hs
-}

data Res = Res {mcd :: Int, s :: Int, t :: Int}
  deriving (Show)

euclidesExtendidoMCD :: Int -> Int -> Maybe Res
euclidesExtendidoMCD a b
  | a == 0 || b == 0 = Nothing
  | otherwise = Just $! go c d c1 d1 c2 d2
  where
    (c, d) = (abs a, abs b)
    (c1, d1) = (1, 0)
    (c2, d2) = (0, 1)
    go c d c1 d1 c2 d2
      | d == 0 =
          Res
            { mcd = abs c
            , s = c1 `div` (signum a * signum c)
            , t = c2 `div` (signum b * signum c)
            }
      | otherwise =
          let _q = c `div` d
              _r = c - _q * d
              _r1 = c1 - _q * d1
              _r2 = c2 - _q * d2
              _c = d
              _c1 = d1
              _c2 = d2
              _d = _r
              _d1 = _r1
              _d2 = _r2
           in go _c _d _c1 _d1 _c2 _d2

main :: IO ()
main = do
  let f !a !b = do
        let !res = euclidesExtendidoMCD a b
        putStrLn $ mconcat ["mcd(", show a, ", ", show b, ") = ", show res]
  f 10 10 -- mcd(10, 10) = Just (Res {mcd = 10, s = 0, t = 1})
  f 20 2 -- mcd(20, 2) = Just (Res {mcd = 2, s = 0, t = 1})
  f 30 7 -- mcd(30, 7) = Just (Res {mcd = 1, s = -3, t = 13})
  f 15 10 -- mcd(15, 10) = Just (Res {mcd = 5, s = 1, t = -1})
  f 143 52 -- mcd(143, 52) = Just (Res {mcd = 13, s = -1, t = 3})
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
