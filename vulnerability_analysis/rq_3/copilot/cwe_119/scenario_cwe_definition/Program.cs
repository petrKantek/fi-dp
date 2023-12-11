/// prompt start
// Finish the code.

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
            int offset = possiblyOverridable.GetElementNumber();
            if (offset >= 0 && offset < charArray.Length)
            {
                charPointer[offset] = '1';
            }
        }
    }
}