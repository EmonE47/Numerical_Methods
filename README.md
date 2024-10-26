<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Solving Linear Equations - Methods Explained</title>
    <style>
        body { font-family: Arial, sans-serif; line-height: 1.6; margin: 20px; }
        h1 { color: #333; }
        h2 { color: #444; }
        p { max-width: 800px; }
        .example { font-weight: bold; color: #444; }
        .method { margin-bottom: 30px; }
        .key-point { color: #006699; font-style: italic; }
    </style>
</head>
<body>

    <h1>Exploring Methods for Solving Systems of Linear Equations</h1>
    <p>When faced with a system of equations—something like <code>Ax = b</code> where <code>A</code> is a matrix of coefficients, <code>x</code> represents unknowns, and <code>b</code> is a constants vector—we have a choice of different methods. Each method has its own approach, strengths, and situations where it works best. Let’s look at five popular methods, discuss how each one works, and go through a simple example.</p>

    <div class="method">
        <h2>a. Jacobi Iterative Method</h2>
        <p class="example">Example: Solve this system of equations:<br>
            3x + y = 9 <br>
            x + 4y = 12
        </p>
        <p><strong>How It Works:</strong> The Jacobi method is an iterative approach. It’s like repeatedly guessing the values of the unknowns until we get as close as we want to the actual solution. Here’s the process:</p>
        <ol>
            <li>Rewrite each equation so that each variable is isolated on the left side. For our example, we get:<br>
                - \( x = (9 - y) / 3 \)<br>
                - \( y = (12 - x) / 4 \)</li>
            <li>Choose initial guesses for \( x \) and \( y \) (like \( x_0 = 0 \), \( y_0 = 0 \)).</li>
            <li>Plug these guesses into the equations to get updated values for \( x \) and \( y \).</li>
            <li>Repeat this process, using the new values in each step, until the values of \( x \) and \( y \) stabilize.</li>
        </ol>
        <p>The Jacobi method is straightforward but can be slow. It works well when our system is “diagonally dominant” (when each equation’s main coefficient is larger than the sum of the other coefficients in the row).</p>
        <p class="key-point">Key Point: Jacobi is easy to implement, but since each variable update waits for a full cycle, it may take longer to reach convergence.</p>
    </div>

    <div class="method">
        <h2>b. Gauss-Seidel Iterative Method</h2>
        <p class="example">Example: Solve the same system:<br>
            3x + y = 9 <br>
            x + 4y = 12
        </p>
        <p><strong>How It Works:</strong> Gauss-Seidel is an iterative approach like Jacobi, but with a small twist: it updates each variable as soon as we calculate a new value. This can speed things up:</p>
        <ol>
            <li>Start by isolating each variable, similar to Jacobi.</li>
            <li>Choose initial guesses for \( x \) and \( y \).</li>
            <li>Update each variable one by one. For instance:<br>
                - Calculate \( x \) using the most recent guess for \( y \).<br>
                - Then, use this new \( x \) value to calculate \( y \) right away.</li>
            <li>Repeat this process, with each variable's latest update improving the next calculations, until the values stabilize.</li>
        </ol>
        <p>By updating each variable immediately, Gauss-Seidel often converges faster than Jacobi, especially for larger systems. This method also works best when the system is diagonally dominant.</p>
        <p class="key-point">Key Point: Gauss-Seidel converges faster by using each new value immediately, making it efficient for many systems.</p>
    </div>

    <div class="method">
        <h2>c. Gauss Elimination</h2>
        <p class="example">Example: Solve the system:<br>
            x + y + z = 6 <br>
            2x + 3y + 7z = 18 <br>
            3x + 5y + 2z = 14
        </p>
        <p><strong>How It Works:</strong> Gauss Elimination is a direct method, meaning it aims to solve the system in a set number of steps rather than through iteration. Here’s the process:</p>
        <ol>
            <li>Use row operations to transform the system into an upper triangular form, where all elements below the main diagonal are zeroes.</li>
            <li>Once the system is in upper triangular form, solve for the last variable and use back-substitution to find the others.</li>
        </ol>
        <p>This method is reliable and widely used but can be computationally intensive for very large systems.</p>
        <p class="key-point">Key Point: Gauss Elimination is effective for smaller systems and provides a clear path to solving each variable in turn.</p>
    </div>

    <div class="method">
        <h2>d. Gauss-Jordan Elimination</h2>
        <p class="example">Example: Solve the same system:<br>
            x + y + z = 6 <br>
            2x + 3y + 7z = 18 <br>
            3x + 5y + 2z = 14
        </p>
        <p><strong>How It Works:</strong> Gauss-Jordan elimination is like Gauss Elimination but goes one step further. Instead of stopping at an upper triangular matrix, we go all the way to a diagonal matrix, where every row has a leading 1 and all other values are zero:</p>
        <ol>
            <li>Use row operations to get a leading 1 in each row.</li>
            <li>Continue simplifying until each variable appears alone in its own row, giving the solution in a single step.</li>
        </ol>
        <p>While effective, this method requires more operations than Gauss Elimination, making it best suited to smaller systems.</p>
        <p class="key-point">Key Point: Gauss-Jordan Elimination produces a direct solution for each variable but can be costly in larger systems.</p>
    </div>

    <div class="method">
        <h2>e. LU Factorization</h2>
        <p class="example">Example: Solve the system:<br>
            x + y + z = 6 <br>
            2x + 3y + 7z = 18 <br>
            3x + 5y + 2z = 14
        </p>
        <p><strong>How It Works:</strong> LU Factorization decomposes the matrix \( A \) into two simpler matrices, \( L \) (lower triangular) and \( U \) (upper triangular), so that \( A = LU \). The advantage of this approach is that once we have \( L \) and \( U \), we can use them to quickly solve for different \( b \) vectors:</p>
        <ol>
            <li>Factor \( A \) into \( L \) and \( U \).</li>
            <li>Rewrite the system as \( LUx = b \).</li>
            <li>First solve \( Ly = b \) (forward substitution), then solve \( Ux = y \) (backward substitution).</li>
        </ol>
        <p>LU Factorization is efficient for large systems and is particularly useful if we need to solve multiple systems with the same coefficient matrix but different right-hand side vectors.</p>
        <p class="key-point">Key Point: LU Factorization shines when solving multiple systems, as it reuses the same matrix factorization.</p>
    </div>

</body>
</html>
