fun parse file =
    let
	(* A function to read an integer from specified input. *)
        fun readInt input = 
	    Option.valOf (TextIO.scanStream (Int.scan StringCvt.DEC) input)

	(* Open input file. *)
    	val inStream = TextIO.openIn file

        (* Read an integer (number of countries) and consume newline. *)
	val n = readInt inStream
	val _ = TextIO.inputLine inStream

        (* A function to read N integers from the open file. *)
	fun readInts 0 acc = rev acc
	  | readInts i acc = readInts (i - 1) (readInt inStream :: acc)
    in
   	(n, readInts n [])
    end

fun find_fair numbers =
    let
        val size = length numbers
        val total_count = List.foldl op+ 0 numbers
        val rec loop = fn (k, j, sub_seq, min) =>
            if k = size then Option.valOf min
            else let
                val diff = abs(total_count - 2 * sub_seq)
                val min' = Int.min(diff, Option.valOf min)
            in
                if j = k then
                    if j = size - 1 then min'
                    else loop(k, j + 1, sub_seq + List.nth(numbers, j + 1), SOME min')
                else if j >= size - 1 orelse sub_seq >= total_count - sub_seq then
                    loop(k + 1, j, sub_seq - List.nth(numbers, k), SOME min')
                else
                    loop(k, j + 1, sub_seq + List.nth(numbers, j + 1), SOME min')
            end
    in
        loop(0, 0, hd numbers, Int.maxInt)  (* Pass Int.maxInt as is *)
    end


fun fairseq file =
    let
        val (n, numbers) = parse file
        val min = find_fair numbers
    in
        print (Int.toString min ^ "\n")
    end;

