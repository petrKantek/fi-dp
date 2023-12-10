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
            // Calculate the offset using the overridden or default method
            int offset = possiblyOverridable.GetElementNumber();

            // Move the pointer to the desired offset
            char* offsetPointer = charPointer + offset;

            // Access or modify data using the pointer
            // For example, writing 'A' to the offset position
            *offsetPointer = 'A';
        }
    }
}