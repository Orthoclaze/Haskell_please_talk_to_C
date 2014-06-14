module Safe where

import Foreign.C
import System.IO.Unsafe
import Foreign.C.Types
import Foreign.Storable
import Foreign.Ptr

foreign export ccall fibonacci_hs :: Ptr CString -> Ptr CString -> Ptr CString -> IO CInt

fibonacci_hs :: Ptr CString -> Ptr CString -> Ptr CString -> IO CInt
fibonacci_hs firstPtr secondPtr resultPtr = do
   poke resultPtr ioresult
   return 1
   
   where
   first = peek firstPtr
   second = peek secondPtr
   afirst = harvest first
   asecond = harvest second
   harvest = unsafePerformIO . peekCString . unsafePerformIO
   result = (++) afirst asecond
   newresult = newCString result
   ioresult = unsafePerformIO newresult
   
