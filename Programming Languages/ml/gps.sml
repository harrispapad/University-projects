* https://www.codewars.com/kata/56484848ba95170a8000004d/ocaml *

fun speed f d s = (d - f) * 3600.0 / Real.fromInt(s)

fun gps s l =
  let
    fun aux [] top = Real.floor top
      | aux [_] top = Real.floor top
      | aux (f :: d :: t) top =
        let
          val v = speed f d s
          val newTop = if v > top then v else top
        in
          aux (d :: t) newTop
        end
  in
    aux l 0.0
  end
