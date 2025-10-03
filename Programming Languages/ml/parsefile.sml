
fun parse file =
    let
        (* Open input file. *)
        val inStream = TextIO.openIn file

        (* Ignore the first line *)
        val _ = TextIO.inputLine inStream

        (* A function to read integers from the open file until EOF. *)
        fun readInts () =
            case TextIO.inputLine inStream of
                NONE => [] (* No more input, return empty list *)
              | SOME line => let
                                val values = String.tokens (fn c => c = #" ") line
                             in
                                map (fn s => Option.valOf (Int.fromString s)) values @ readInts ()
                             end

        val numbers = readInts ()

        (* Close the input stream. *)
        val _ = TextIO.closeIn inStream
    in
        numbers
    end
