{-# LANGUAGE CApiFFI #-}

import Data.Function
import Foreign.C.Types

foreign import capi "header.h f" f :: CInt -> IO CInt
