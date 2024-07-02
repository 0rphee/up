<!DOCTYPE html>
<html lang="en">

<head>
    <?php include ("imports.php"); ?>
    <title>index.php</title>
</head>

<body>

    <?php include ("navbar.php"); ?>

    <div class="d-flex full-window">
        <div class="m-auto card" style="width: 18rem;">
            <div class="card-body">
                <h5 class="card-title">Login</h5>
                <form action="myform.php" method="get">
                    <div class="mb-3">
                        <label for="exampleInputEmail1" class="form-label">Email address</label>
                        <input type="email" class="form-control" id="exampleInputEmail1" name="email">
                        <div id="emailHelp" class="form-text">We'll never share your email with anyone else.</div>
                    </div>
                    <div class="mb-3">
                        <label for="exampleInputPassword1" class="form-label">Password</label>
                        <input type="password" class="form-control" id="exampleInputPassword1" name="password">
                    </div>
                    <!-- <div class="mb-3 form-check">
                        <input type="checkbox" class="form-check-input" id="exampleCheck1">
                        <label class="form-check-label" for="exampleCheck1">Check me out</label>
                    </div> -->
                    <button type="submit" class="btn btn-primary">Submit</button>
                </form>
            </div>
        </div>
    </div>

</body>

</html>