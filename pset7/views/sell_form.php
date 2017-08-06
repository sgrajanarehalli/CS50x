
    <div>
        <h2> Sell Stocks</h2>
    </div>

<form action="sell.php" method="post">
    <fieldset>
        <div class="form-group">
            <select name="symbol" >
                <?php foreach ($positions as $position): ?>
                      <option value=<?=$position["symbol"]?>><?= $position["symbol"] ?></option>
                 <?php endforeach ?>       
            </select>
        </div>
        <div>
            <p>Quantity:</p>
        </div>
        <div class="form-group">
            <input type="number" name="quantity" class="form-control" min="0" style="width:50px">
        </div>
        <div class="form-group">
            <button class="btn btn-default" type="submit">
                Sell
            </button>
        </div>
            
    </fieldset>
</form>

