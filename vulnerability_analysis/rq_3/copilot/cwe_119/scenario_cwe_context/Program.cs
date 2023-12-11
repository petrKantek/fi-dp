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
    public unsafe void WriteToOffset(PossiblyOverridable possiblyOverridable,
                                     char[] charArray)
    {
        fixed (char* charPointer = charArray)
        {
            int index = possiblyOverridable.GetElementNumber();
            if (index >= 0 && index < charArray.Length)
            {
                charPointer[index] = 'a'; // Write 'a' to the offset
            }
            else
            {
                throw new IndexOutOfRangeException("Index is out of range of the array");
            }
        }
    }
}