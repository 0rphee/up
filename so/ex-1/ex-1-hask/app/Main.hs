module Main (main) where

import Control.Concurrent.MVar
import Control.Concurrent
import Control.Monad (forever)

main :: IO ()
main = do 
  mvar <- newMVar (0 :: Int)
  putStrLn "Inicio\n\n"
  forkIO $ forever (secondThread mvar)
  forever (mainThread mvar)

secondThread :: (Show a, Num a) =>  MVar a -> IO ()
secondThread mvar = do
  modifyMVar_ mvar (\val ->  do
    putStrLn $ "Modificacion " ++ show (val + 1)
    pure $ val+1)
  threadDelay 100000

mainThread :: (Show a, Ord a, Num a) => MVar a -> IO ()
mainThread mvar = do 
  a <- readMVar mvar
  putStrLn $ "Lectura " ++ show a
  if a >= 100
  then error "final"
  else threadDelay 100000
  

  




