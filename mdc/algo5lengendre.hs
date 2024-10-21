{-# HLINT ignore "Redundant if" #-}
{-# LANGUAGE MultiWayIf #-}
{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}

module Main (main) where

import Control.Monad (forM_, when)
import Control.Monad.ST (runST)
import Data.Array (Array, listArray, (!), (//))
import Data.Foldable (Foldable (foldl'), forM_)
import Data.STRef (modifySTRef', newSTRef, readSTRef)
import Text.Printf (printf)

{-
    se puede correr el código en https://play.haskell.org/
    o para instalar el compilador de haskell y correrlo: https://www.haskell.org/ghcup/
    > runghc algoritmo1.hs
-}

myMod :: Word -> Word -> Word
myMod a b
  | (0, 0) <- (a, b) = 0
  | otherwise = go a
  where
    go !r
      | r >= b = go (r - b)
      | otherwise = r

esPrimo :: Word -> Bool
esPrimo n
  | n <= 1 = False
  | n <= 3 = True
  | even n || ((n `myMod` 3) == 0) = False
  | otherwise = go 5
  where
    go i
      | (i * i) <= n =
          if ((n `myMod` i) == 0) || ((n `myMod` i + 2) == 0)
            then False
            else go (i + 6)
      | otherwise = True

main :: IO ()
main = do
  let f x = do
        let str = printf "esPrimo(%d) = %s" x (show $ esPrimo x)
        putStrLn str
  let g n = do
        let (c, arr) = contarPrimos n
        putStrLn $ printf "contarPrimos(%d) = %d\n%s" n c (show arr)

  forM_ [1, 2, 3, 4, 5, 6, 13, 15, 19, 21, 123, 97, 83] f
  g 100

contarPrimos :: Word -> (Word, Array Word Bool)
contarPrimos n = runST $ do
  arrRef <- newSTRef primoListInicial
  eratostenes arrRef
  arrFinal <- readSTRef arrRef
  let primosCount = foldl' (\c v -> if v then c + 1 else c) 0 arrFinal
  pure (primosCount, arrFinal)
  where
    primoListInicial = listArray (2, n) $ [True | _ <- [1 .. n + 1]]
    final = floor $ sqrt $ fromIntegral n
    eratostenes ref = do
      forM_ [2 .. final] $ \p -> do
        arr <- readSTRef ref
        when (arr ! p) $ do
          forM_ [p * p, (p * p) + p .. n] $ \i -> do
            modifySTRef' ref $ \arr -> arr // [(i, False)]
