<body>
      
### Ahsanul Islam Emon - 2107115

### Khadimul Islam Mahi - 2107076

### Tanha Sayed Ahona - 2107093

These are some common methods to solve systems of linear equations, of the form Ax = b, where A is the matrix of coefficients, x is the vector of unknowns, and b is the constant vector.<br>


a. Jacobi iterative method <br>
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

<h2>2. Solution of Non-linear Equations</h2>
<p>Non-linear equations often require specialized methods to solve because they do not produce a straight line. The following methods approximate roots by iteration, aiming to find points where <code>f(x) = 0</code>.</p>

<h3>a. Bisection Method</h3>
<p>The Bisection Method is an iterative, simple root-finding technique for continuous functions, guaranteed to converge within an interval <code>[a, b]</code> where <code>f(a)</code> and <code>f(b)</code> have opposite signs.</p>
<p><strong>Steps:</strong></p>
<ol>
    <li>Set <code>a</code> and <code>b</code> as the endpoints of an interval containing a root, where <code>f(a)</code> and <code>f(b)</code> have opposite signs.</li>
    <li>Calculate the midpoint <code>c = (a + b) / 2</code>.</li>
    <li>Evaluate <code>f(c)</code>:
        <ul>
            <li>If <code>f(c) = 0</code>, then <code>c</code> is the root.</li>
            <li>If <code>f(c) * f(a) < 0</code>, the root is in <code>[a, c]</code>; set <code>b = c</code>.</li>
            <li>Otherwise, the root is in <code>[c, b]</code>; set <code>a = c</code>.</li>
        </ul>
    </li>
    <li>Repeat until <code>|b - a|</code> is within the desired tolerance.</li>
</ol>
<p><strong>Example:</strong> Solve <code>f(x) = x^2 - 4</code> within the interval [1, 3]. The root is <code>x = 2</code>.</p>

<p><strong>Advantages:</strong> The Bisection Method is easy to implement and guarantees convergence if the initial interval contains a root. However, it can be slower than other methods for high accuracy requirements.</p>

<hr>

<h3>b. False Position Method (Regula Falsi)</h3>
<p>Also known as Regula Falsi, this method is similar to the Bisection Method but instead uses a secant line through points <code>(a, f(a))</code> and <code>(b, f(b))</code> to find the intersection, aiming to converge faster by adjusting the interval based on the function values.</p>
<p><strong>Steps:</strong></p>
<ol>
    <li>Calculate the new point:
        <br><code>c = b - (f(b) * (b - a)) / (f(b) - f(a))</code></li>
    <li>Update the interval:
        <ul>
            <li>If <code>f(c) * f(a) < 0</code>, the root is in [a, c]; set <code>b = c</code>.</li>
            <li>If <code>f(c) * f(b) < 0</code>, the root is in [c, b]; set <code>a = c</code>.</li>
        </ul>
    </li>
    <li>Repeat until the root is found within the desired accuracy.</li>
</ol>
<p><strong>Example:</strong> Solve <code>f(x) = x^2 - 4</code> within the interval [1, 3].</p>

<p><strong>Advantages:</strong> The False Position Method converges more quickly than the Bisection Method for some functions. However, it can converge slowly if one endpoint of the interval remains fixed.</p>

<hr>

<h3>c. Secant Method</h3>
<p>The Secant Method uses a linear approximation to find the root, calculating new points based on the previous two approximations, rather than an interval. It does not require <code>f(x)</code> to change sign between points.</p>
<p><strong>Steps:</strong></p>
<ol>
    <li>Choose two initial points <code>x0</code> and <code>x1</code>.</li>
    <li>Calculate the next point:
        <br><code>x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0))</code></li>
    <li>Update points: Set <code>x0 = x1</code> and <code>x1 = x2</code> and repeat until convergence.</li>
</ol>
<p><strong>Example:</strong> To find the root of <code>f(x) = x^2 - 4</code>, start with <code>x0 = 1</code> and <code>x1 = 3</code>.</p>

<p><strong>Advantages:</strong> The Secant Method is often faster than both the Bisection and False Position methods but may be less stable if the starting points are not close to the actual root.</p>

<hr>

<h3>d. Newton-Raphson Method</h3>
<p>The Newton-Raphson method is a powerful technique for solving nonlinear equations by leveraging the derivative of the function to make iterative approximations. This method requires the function to be differentiable.</p>
<p><strong>Steps:</strong></p>
<ol>
    <li>Start with an initial guess <code>x0</code>.</li>
    <li>Calculate the next approximation:
        <br><code>xn+1 = xn - f(xn) / f'(xn)</code></li>
    <li>Repeat until convergence, meaning that <code>|xn+1 - xn|</code> is within the tolerance.</li>
</ol>
<p><strong>Example:</strong> Find the root of <code>f(x) = x^2 - 4</code> with an initial guess of <code>x0 = 3</code>. Using the derivative, <code>f'(x) = 2x</code>, the iterations converge to <code>x = 2</code>.</p>

<p><strong>Advantages:</strong> Newton-Raphson converges faster than other methods, especially when the initial guess is close to the root. However, it requires the derivative and can diverge if started far from the root or if <code>f'(x) = 0</code> near the root.</p>

<hr>

<h2>3. Solution of Differential Equations</h2>

<h3>a. Runge-Kutta Method (4th Order)</h3>
<p>The Runge-Kutta method, specifically the 4th order, is a widely used technique for solving first-order differential equations <code>dy/dx = f(x, y)</code> with a given initial value. It is known for its accuracy and efficiency in approximating solutions.</p>
<p><strong>Steps:</strong></p>
<ol>
    <li>Start with an initial point <code>(x0, y0)</code> and a step size <code>h</code>.</li>
    <li>Calculate four intermediate slopes:
        <ul>
            <li><code>k1 = h * f(xn, yn)</code></li>
            <li><code>k2 = h * f(xn + h/2, yn + k1/2)</code></li>
            <li><code>k3 = h * f(xn + h/2, yn + k2/2)</code></li>
            <li><code>k4 = h * f(xn + h, yn + k3)</code></li>
        </ul>
    </li>
    <li>Estimate <code>y(n+1)</code> using:
        <br><code>y(n+1) = yn + (1/6)(k1 + 2k2 + 2k3 + k4)</code></li>
    <li>Update <code>x(n+1) = xn + h</code> and repeat.</li>
</ol>
<p><strong>Example:</strong> Solve <code>dy/dx = x + y</code> with <code>y(0) = 1</code> and <code>h = 0.1</code>.</p>

<p><strong>Advantages:</strong> The 4th-order Runge-Kutta method offers high accuracy with relatively simple computations and is suitable for a broad range of differential equations.</p>
<h2>4. Matrix Inversion</h2>

<h3>Matrix Inversion Overview</h3>
<p>Matrix inversion is a fundamental concept in linear algebra that allows us to solve systems of linear equations represented in matrix form. If we have a square matrix <code>A</code>, its inverse, denoted as <code>A<sup>-1</sup></code>, is defined such that:</p>
<p><code>A * A<sup>-1</sup> = I</code>, where <code>I</code> is the identity matrix.</p>
<p>The inverse of a matrix exists only if the matrix is non-singular (i.e., its determinant is non-zero). Matrix inversion is widely used in various fields, including engineering, physics, computer science, and economics, particularly for solving linear systems and performing linear transformations.</p>

<h3>Methods for Matrix Inversion</h3>
<p>Several methods exist to compute the inverse of a matrix. One effective method is the Gauss-Jordan elimination, which involves performing row operations on an augmented matrix.</p>

<h3>Gauss-Jordan Elimination Method</h3>
<p>The Gauss-Jordan elimination method transforms the augmented matrix <code>[A | I]</code> into reduced row echelon form (RREF), effectively finding the inverse.</p>

<h4>Steps:</h4>
<ol>
    <li><strong>Form the Augmented Matrix:</strong> Create an augmented matrix <code>[A | I]</code>, where <code>I</code> is the identity matrix of the same size as <code>A</code>.</li>
    <li><strong>Row Operations:</strong> Perform the following row operations to transform the left side (matrix <code>A</code>) into the identity matrix:
        <ul>
            <li><strong>Row Swap:</strong> Swap two rows if necessary.</li>
            <li><strong>Scaling:</strong> Multiply a row by a non-zero scalar.</li>
            <li><strong>Row Addition/Subtraction:</strong> Add or subtract multiples of one row from another to eliminate variables.</li>
        </ul>
    </li>
    <li><strong>Achieve Reduced Row Echelon Form:</strong> Continue performing row operations until the left side of the augmented matrix is the identity matrix. The right side will then be the inverse matrix <code>A<sup>-1</sup></code>.</li>
</ol>

<h4>Example:</h4>
<p>Consider the matrix <code>A = [[4, 2], [3, 1]]</code>. We want to find its inverse using Gauss-Jordan elimination:</p>
<pre>
1. Form the augmented matrix:
   [ 4  2 | 1 0 ]
   [ 3  1 | 0 1 ]

2. Perform row operations:
   a) R1 = R1 / 4
      [ 1  0.5 | 0.25 0 ]
      [ 3  1   | 0    1 ]

   b) R2 = R2 - 3*R1
      [ 1  0.5 | 0.25 0 ]
      [ 0 -0.5 | -0.75 1 ]

   c) R2 = R2 / -0.5
      [ 1  0.5 | 0.25 0 ]
      [ 0  1   | 1.5 -2 ]

   d) R1 = R1 - 0.5*R2
      [ 1  0   | -0.5 1 ]
      [ 0  1   | 1.5 -2 ]

Final form:
   [ 1  0 | -0.5 1 ]
   [ 0  1 | 1.5 -2 ]
</pre>
<p>Thus, the inverse is <code>A<sup>-1</sup> = [[-0.5, 1], [1.5, -2]]</code>.</p>

<h3>Advantages of Matrix Inversion</h3>
<ul>
    <li><strong>Solving Linear Systems:</strong> Matrix inversion provides a direct method for solving systems of linear equations of the form <code>Ax = b</code> by calculating <code>x = A<sup>-1</sup>b</code>.</li>
    <li><strong>Linear Transformations:</strong> Inverse matrices are essential for reversing transformations applied to data or geometric figures in various applications.</li>
    <li><strong>Computation of Determinants:</strong> The process of finding an inverse often involves determinants, enhancing understanding of matrix properties.</li>
</ul>

<h3>Key Points to Remember</h3>
<ul>
    <li>The inverse of a matrix exists only if the matrix is square and non-singular (determinant ≠ 0).</li>
    <li>Row operations in Gauss-Jordan elimination can be computationally intensive for large matrices.</li>
    <li>Other methods for finding matrix inverses include using adjugates and cofactors, but Gauss-Jordan is often preferred for its straightforward approach.</li>
</ul>

</body>
