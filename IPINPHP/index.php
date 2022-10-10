<!DOCTYPE html>
<html lang="en">
<head>
    <!-- CSS only -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-iYQeCzEYFbKjA/T2uDLTpkwGzCiq6soy8tYaI1GyVh/UjpbCx/TYkiZhlZB6+fzT" crossorigin="anonymous">
    <!-- JavaScript Bundle with Popper -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.1/dist/js/bootstrap.bundle.min.js" integrity="sha384-u1OknCvxWvY5kfmNBILK2hRnQC3Pr17a+RTT6rIHI7NnikvbZlHgTPOOmMi466C8" crossorigin="anonymous"></script>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="styleindex.css">
    <link rel="preconnect" href="https://fonts.googleapis.com">
<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
<link href="https://fonts.googleapis.com/css2?family=Annie+Use+Your+Telescope&display=swap" rel="stylesheet">
    <title>SPARK BANK</title>
</head>
<body>
    
  <nav class="navbar navbar-dark bg-dark fixed-top">
    <div class="container-fluid">
      <a class="navbar-brand" href="#" style="font-size: 30px;" >Spårk B@ñk</a>
      <button class="navbar-toggler" type="button" data-bs-toggle="offcanvas" data-bs-target="#offcanvasDarkNavbar" aria-controls="offcanvasDarkNavbar">
        <span class="navbar-toggler-icon"></span>
      </button>
      <div class="offcanvas offcanvas-end text-bg-dark" tabindex="-1" id="offcanvasDarkNavbar" aria-labelledby="offcanvasDarkNavbarLabel">
        <div class="offcanvas-header">
          <h5 class="offcanvas-title" id="offcanvasDarkNavbarLabel" style="font-size: 30px;">Welcome</h5>
          <button type="button" class="btn-close btn-close-white" data-bs-dismiss="offcanvas" aria-label="Close"></button>
        </div>
        <div class="offcanvas-body">
          <ul class="navbar-nav justify-content-end flex-grow-1 pe-3">
            <li class="nav-item">
              <a class="nav-link active" aria-current="page" href="index.php" style="font-size: 20px;">Home</a>
            </li>
            <li class="nav-item">
                <a class="nav-link active" aria-current="page" href="makepayment.php" style="font-size: 20px;">Make Payment</a>
              </li>
              <li class="nav-item">
                <a class="nav-link active" aria-current="page" href="Transaction.php" style="font-size: 20px;">Transactions</a>
              </li>
              <li class="nav-item">
                <a class="nav-link active" aria-current="page" href="Viewallcustomers.php" style="font-size: 20px;">View All Customers</a>
              </li>
          </ul>
        </div>
      </div>
    </div>
  </nav>

    <div class="hometext" style="font-size: 30px;">
        <h1>Welcome To</h1>
        <h1 style="color: green; font-size: 40px;">Spark Bank</h1>
        <h4>Make Payments easy!!!</h4>
        <h6>You can transfer money with other users also</h6>
    </div>
    <!--INSERT INTO `user data` (`Name`, `Account No.`, `Balance`) VALUES ('Pranav Redij', '1111111111', '1000000'); -->
    <!--INSERT INTO `user data` (`Name`, `Account No.`, `Balance`) VALUES ('Akshaya Redij', '2121212121', '1000000');-->
</body>
</html>