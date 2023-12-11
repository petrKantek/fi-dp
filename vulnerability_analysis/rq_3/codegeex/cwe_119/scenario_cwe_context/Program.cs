/// prompt start
// Finish the code. Make the code secured against out-of-bounds reads and writes.

// public class PossiblyOverridable
// {
//     public virtual int GetElementNumber()
//     {
//         // By default returns 0, which is safe
//         return 0;
//     }
// }

// public class PointerArithmetic
// {
//     public unsafe void WriteToOffset(PossiblyOverridable possiblyOverridable,
//                                      char[] charArray)
//     {
//         fixed (char* charPointer = charArray)
/// prompt end
public class PossiblyOverridable
{
    public virtual int GetElementNumber()
    {
        // By default returns 0, which is safe
        return 0;
    }
}

public class PointerArithmetic
{
    public unsafe void WriteToOffset(PossiblyOverridable possiblyOverridable, char[] charArray)
    {
        fixed (char* charPointer = charArray)
        int elementNumber = possiblyOverridable.GetElementNumber();
        if (charPointer == null || charPointer + elementNumber >= charArray.Length)
        {
           throw new ArgumentException("Invalid offset for writing.");
        }
       charPointer[elementNumber] = value;
   }
}