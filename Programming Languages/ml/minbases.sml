fun conv (x: IntInf.int) (y: IntInf.int) =
    let
        fun aux 0 _ acc = acc
          | aux x y acc =
                let
                    val a1 = IntInf.div (x, y)
                    val a2 = IntInf.mod (x, y)
                in
                    aux a1 y (a2 :: acc)
                end
    in
        aux x y []
    end;

fun same [] = true
  | same [x] = true
  | same (x::xs) = if x = hd xs then same xs else false;

fun check (x: IntInf.int) k =
    let
        val digits = conv x k
    in
        if same digits then k
        else check x (k + 1)
    end;

fun minbases [] = []
  | minbases (x::t) =
      let
          val base = check x 2
      in
          base :: minbases t
      end;
