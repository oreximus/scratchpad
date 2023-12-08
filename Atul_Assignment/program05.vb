Module Module1
    Sub Main()
        ' Variables to store the sum
        Dim sum As Integer = 0

        ' Loop to print numbers from 1 to 30 and calculate the sum
        For i As Integer = 1 To 30
            Console.WriteLine($"Number: {i}")
            sum += i
        Next

        ' Display the sum
        Console.WriteLine($"Sum of numbers from 1 to 30: {sum}")

        Console.ReadLine()
    End Sub
End Module
