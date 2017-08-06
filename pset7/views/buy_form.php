 <div><h2> Buy Stocks</h2></div>

<form action="buy.php" method="post">
    <fieldset>
        <div class="form-group">
            <input name="symbol" class="form-control" type="text" placeholder="Enter Stock Symbol">
        </div>
        <div>
            <p>Quantity:</p>
        </div>
        <div class="form-group">
            <input type="number" name="quantity" class="form-control" min="0" style="width:50px">
        </div>
        <div class="form-group">
            <button class="btn btn-default" type="submit">
                Buy
            </button>
        </div>
            
    </fieldset>
</form>
