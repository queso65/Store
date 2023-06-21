$(function(){
	const links_with_id = $('.add_item');
	const cart_value = $("#cart_count");
	const cart_cost = $("#cart_cost");
		
	$.each(links_with_id, function(){
		$(this).bind('click', function(){
			let current_id = $(this).attr('data-id');
			const button_goods = $(this);
			
			
			$.post( "api.php", { "good_id": current_id })
			.done(function( data ){
				
                var d = $.parseJSON(data);
					
				cart_value.html(d.current_cart_value);
				cart_cost.html(d.cart_cost);
				button_goods.html(d.text_button_good);
				
			});
		});
	});
});

$(function(){
	const button_delate = $('.delate__item__text-cart');
	const cart_value = $("#cart_count");
	const cart_cost = $("#cart_cost");
	const iteem_cart = $('.item-cart');
	const total_price = $('.total');
	
	$.each(button_delate, function(){
		$(this).bind('click', function(){
			let current_id = $(this).attr('data-id');
			
            $.each(iteem_cart, function(){
				let item_id = $(this).attr('data-id');
				if(item_id == current_id){
					$(this).css('display', 'none');
				}
	        }); 


			$.post( "api.php", { "good_id": current_id })
			.done(function( data ){
				 var d = $.parseJSON(data);
					
				cart_value.html(d.current_cart_value);
				cart_cost.html(d.cart_cost);
				total_price.html(d.cart_cost);
			});
		});
    });
});

$(function(){
	const button_delate_user = $('.delate_user_button');
	const user_line = $('.user_line');
	
	$.each(button_delate_user, function(){
		let current_id = $(this).attr('data-id');
		$(this).bind('click', function(){
			$.post( "vendor/admin_functions.php", { "delate_id": current_id })
			.done(function( data ){
				if(data == "no_rights"){
					window.location = 'index.php';
				}
				alert(data);
				if(data == "no_login"){
					window.location = 'login.php';
				}
				$.each(user_line, function(){
				    let item_id = $(this).attr('data-id');
				    if(item_id == current_id){
					    $(this).css('display', 'none');
				    }
	            }); 
			});
		});
    });
});




$(function(){
	const rights = $('.rights');
	const role = $('.role');
	
	$.each(rights, function(){
		$(this).bind('click', function(){
			let current_id = $(this).attr('data-id');
			
			a = $(this).text();
			if(a == "наз. модератором"){
				$(this).html("снять модератора");
			}
			else{
				$(this).html("наз. модератором");
			}
			
			$.post( "vendor/admin_functions.php", { "user_id": current_id })
			.done(function( data ){
				if(data == "no_rights"){
					window.location = 'index.php';
				}
				if(data == "no_login"){
					window.location = 'login.php';
				}
				$.each(role, function(){
				let role_id = $(this).attr('data-id');
				if(role_id == current_id){
					$(this).html(data);
				}
	        }); 
			});
		});
    });
});

$(function(){
	const cart_informer_button = $('.cart-informer__button');
	const cart_value = $("#cart_count");
	
	
	cart_informer_button.click(function(){
		value = cart_value.text();
		$.post( "api.php", { "cart_link": 1 })
		.done(function( data ){
		if(value == 0){
		}
		else if (data == 0){
			window.location = 'login.php';
		}
		else{
			window.location = 'cart.php';
		}
		});
	});
});


$(function(){
	const ban = $('.ban_user_button');
	
	$.each(ban, function(){
		$(this).bind('click', function(){
			let current_id = $(this).attr('data-id');
			
			a = $(this).text();
			if(a == "забанить"){
				$(this).html("разбанить");
			}
			else{
				$(this).html("забанить");
			}
			
			$.post( "vendor/admin_functions.php", { "ban_id": current_id })
			.done(function( data ){
				if(data == "no_rights"){
					window.location = 'index.php';
				}
				alert(data);
				if(data == "no_login"){
					window.location = 'login.php';
				}
			});
		});
    });
});

