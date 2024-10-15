{-# LANGUAGE MultiWayIf #-}

module Main (main) where

import Text.Printf

{-
    se puede correr el código en https://play.haskell.org/
    o para instalar el compilador de haskell y correrlo: https://www.haskell.org/ghcup/
    > runghc algoritmo1.hs
-}

data MCDRes = Res {mcd :: !Int, s :: !Int, t :: !Int}
  deriving (Show)

euclidesExtendidoMCD :: Int -> Int -> Maybe MCDRes
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

divi
  :: Int
  -> Int
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
              | otherwise -> (b - r, -q - 1)
  where
    go !r !q
      | r >= b = go (r - b) (q + 1)
      | otherwise = (r, q)

data DiofRes = DiofRes
  {x0 :: !Int, x1 :: !Int, y0 :: !Int, y1 :: !Int}

-- diofantica a b = Maybe (x, y)
diofantica :: Int -> Int -> Int -> Maybe DiofRes
diofantica a b c = do
  Res {mcd = d, s, t} <- euclidesExtendidoMCD b a
  (r1, q1) <- divi c d
  (r2, x1) <- divi b d
  (r3, y1) <- divi a d
  case (r1, r2, r3) of
    (0, 0, 0) ->
      Just $
        let x0 = c * t
            y0 = c * s
         in DiofRes {x0 = x0, x1 = x1, y1 = y1, y0 = y0}
    _ -> Nothing

mostrarDiof :: Int -> Int -> Int -> DiofRes -> String
mostrarDiof a b c (DiofRes {x0, x1, y0, y1}) =
  printf "diof(%d,%d,%d) = {%s, %s}" a b c x y
  where
    x :: String = h "x" x0 x1 $ if x1 >= 0 then "+" else "-"
    y :: String = h "y" y0 y1 $ if y1 >= 0 then "-" else "+"
    h n a0 a1 expr =
      printf "%s = %d %s %dt" n a0 expr (abs a1)

main :: IO ()
main = do
  let f a b c = do
        let res = diofantica a b c
        let txt =
              maybe
                ( printf
                    "Nothing: input inválido (%d,%d,%d), puede que las soluciones no pertenezcan a los numeros enteros"
                    a
                    b
                    c
                )
                (mostrarDiof a b c)
                res
        putStrLn txt
  f 10 10 23 -- Nothing: input inválido (10,10,23), puede que las soluciones no pertenezcan a los numeros enteros
  f 20 2 54 -- diof(20,2,54) = {x = 0 + 1t, y = 54 - 10t}
  f 30 7 2 -- diof(30,7,2) = {x = -6 + 7t, y = 26 - 30t}
  f 15 10 4 -- Nothing: input inválido (15,10,4), puede que las soluciones no pertenezcan a los numeros enteros
  f 143 52 5 -- Nothing: input inválido (143,52,5), puede que las soluciones no pertenezcan a los numeros enteros
  f 3 0 6 -- Nothing: input inválido (3,0,6), puede que las soluciones no pertenezcan a los numeros enteros
  f 1 3 6 -- diof(1,3,6) = {x = 6 + 3t, y = 0 - 1t}
  f 8 (-13) 7 -- diof(8,-13,7) = {x = 35 - 13t, y = 21 - 8t}

-- El código siguiente no correrá en https://play.haskell.org/
-- debido al input, pero si se puede ejecutar localmente
-- (debe tener la misma indentación que las líneas previas).

-- putStrLn "\nEscribe el primer número: "
-- a <- read <$> getLine
-- putStrLn "Escribe el segundo número: "
-- b <- read <$> getLine
-- f a b
