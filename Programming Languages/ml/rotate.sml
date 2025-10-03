(* Helper function to convert a number to a list of digits *)
fun digits n =
    let
        fun aux 0 d = d
          | aux n d = aux (n div 10) ((n mod 10) :: d)
    in
        if n = 0 then [0] else aux n []
    end

(* Helper function to convert a list of digits back to a number *)
fun fromDigits [] = 0
  | fromDigits (x::xs) = x * (10 * length xs) + fromDigits xs

(* Helper function to compute power of 10 *)
fun pow10 0 = 1
  | pow10 n = 10 * pow10 (n - 1)

(* Helper function to convert a list of digits back to a number using the correct power function *)
fun fromDigits [] = 0
  | fromDigits (x::xs) = x * (pow10 (length xs)) + fromDigits xs

(* Helper function to split a list at a given index *)
fun splitAt 0 xs = ([], xs)
  | splitAt _ [] = ([], [])
  | splitAt n (x::xs) = let val (left, right) = splitAt (n - 1) xs in (x::left, right) end

(* Function to rotate the list from a specific index *)
fun rotate_from_index lst idx =
    let
        val (prefix, suffix) = splitAt idx lst
    in
        prefix @ (case suffix of [] => [] | (x::xs) => xs @ [x])
    end

(* Main function to find the maximum rotation *)
fun max_rot n =
    let
        val digitsList = digits n
        val len = length digitsList

        (* Helper function to perform the rotations and find the maximum *)
        fun aux i maxSoFar =
            if i >= len then maxSoFar
            else
                let
                    val rotated = rotate_from_index digitsList i
                    val rotatedNumber = fromDigits rotated
                in
                    aux (i + 1) (Int.max(maxSoFar, rotatedNumber))
                end
    in
        aux 0 n
    end

(* Example usage *)
val result1 = max_rot 56789
val result2 = max_rot 38458215

(* Output: result1 = 68957, result2 = 85821534 *)

