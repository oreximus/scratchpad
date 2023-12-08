Module Module1
    Sub Main()
        Dim number As Integer

        ' Input: Get the number from the user
        Console.Write("Enter a number to find its factorial: ")
        If Integer.TryParse(Console.ReadLine(), number) Then
            ' Calculate and display the factorial
            Console.WriteLine($"Factorial of {number} is: {Factorial(number)}")
        Else
            Console.WriteLine("Invalid input. Please enter a valid integer.")
        End If

        Console.ReadLine()
    End Sub

    ' Recursive function to calculate factorial
    Function Factorial(ByVal n As Integer) As Integer
        If n = 0 Or n = 1 Then
            Return 1
        Else
            Return n * Factorial(n - 1)
        End If
    End Function
End Module
