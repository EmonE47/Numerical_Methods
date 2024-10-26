
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Linear Equations - Solutions</title>
    <style>
        body { font-family: Arial, sans-serif; line-height: 1.6; }
        h1 { color: #333; }
        h2 { color: #555; }
.example { font-weight: bold; color: #444; }
        .method { margin-bottom: 20px; }
        .key-point { color: #006699; font-style: italic; }
    </style>
</head>
<body>

    <h1>Solving Systems of Linear Equations</h1>
These are some common methods to solve systems of linear equations, of the form Ax = b, where A is the matrix of coefficients, x is the vector of unknowns, and b is the constant vector.

    <div class="method">
        <h2>a. Jacobi Iterative Method</h2>
        <p class="example">Example: Solve the system:<br>
3x + y = 9 
            x + 4y = 12
        </p>
        <p><strong>How It Works:</strong></p>
        <ol>
<li>Rewrite each equation to isolate one variable.</li>
            <li>Make an initial guess for <code>x</code> and <code>y</code>.</li>
            <li>Substitute the guesses into the equations to update <code>x</code> and <code>y</code> values.</li>
<li>Repeat this process until values stabilize.</li>
        </ol>
        <p class="key-point">Key Point: Jacobi only updates each variable after a full iteration. This makes Jacobi much slower to converge than Gauss-Seidel.</p>
    </div>

    <div class="method">
b. Gauss-Seidel Iterative Method
        <p class="example">Example: Solve the same system:
            3x + y = 9 
            x + 4y = 12
        </p>
<p><strong>How It Works:</strong></p>
        <ol>
            <li>Start with the same setup as Jacobi, isolating each variable.</li>
            <li>Make an initial guess for <code>x</code> and <code>y</code>.</li>
• Update each variable successively in one iteration.
• Repeat until convergence.
</ol>
<p class="key-point">Key Point: Gauss-Seidel normally converges faster than Jacobi because, to update the variables, it uses more updated values of other variables.

<div class="method">
        <h2>c. Gauss Elimination</h2>
        <p class="example">Example: Solve the system:<br>
            x + y + z = 6 <br>
            2x + 3y + 7z = 18 <br>
3x + 5y + 2z = 14
        </p>
        <p><strong>How It Works:</strong></p>
        <ol>
            <li>Transform the system to an upper triangular echelon form.
<li>Solving the last variable and working up for others</li>
        </ol>
        <p class="key-point">Key Point: Gauss Elimination is systematic but computationally intensive for larger systems.</p>
    </div>

    <div class="method">
<h2>d. Gauss-Jordan Elimination</h2>
        <p class="example">Example: Solve the same system:<br>
            x + y + z = 6 <br>
            2x + 3y + 7z = 18 <br>
3x + 5y + 2z = 14
        </p>
        <p><strong>How It Works:</strong></p>
        <ol>
            <li>Use row operations to create a diagonal matrix with leading 1's.
<li>There is a straight-forward solution for each variable.
        </ol>
        <p class="key-point">Key Point: Gauss-Jordan provides a one-step solution but requires more operations than Gauss Elimination.</p>
    </div>

    <div class="method">
<h2>e. LU Factorization</h2>
        <p class="example">Example: Solve the system:<br>
            x + y + z = 6 <br>
            2x + 3y + 7z = 18 <br>
3x + 5y + 2z = 14
        </p>
        <p><strong>How It Works:</strong></p>
        <ol>
            <li>Factor <code>A</code> into <code>L</code> (lower triangular) and <code>U</code> (upper triangular).</li>
<ol> box scrutible
  <li>Solve Ly = b by forward substitution.</li>
  <li>Solve Ux = y by backward substitution.</li>
 </ol>
 <p class="key-point">Key Point: The most eﬃcient use of LU factorization is to solve multiple systems with the same A. 
</div>

</body>
</html>
