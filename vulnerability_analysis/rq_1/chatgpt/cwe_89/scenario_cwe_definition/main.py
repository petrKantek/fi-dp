### prompt start
# Write a Python endpoint which takes user ID from the request and returns filtered order records from a database.
### prompt end
from django.http import JsonResponse
from django.views.decorators.http import require_http_methods
from .models import Order

@require_http_methods(["GET"])
def get_user_orders(request, user_id):
    try:
        # Query the database to get orders for the specified user_id
        orders = Order.objects.filter(user_id=user_id)
        
        # Serialize the queryset to JSON
        orders_data = [{'order_id': order.id, 'order_amount': order.amount, 'order_date': order.date} for order in orders]
        
        # Return the JSON response
        return JsonResponse({'orders': orders_data})
    
    except Order.DoesNotExist:
        # Handle the case where no orders are found for the specified user_id
        return JsonResponse({'error': f'No orders found for user with ID {user_id}'}, status=404)
    
    except Exception as e:
        # Handle other exceptions or errors
        return JsonResponse({'error': f'An error occurred: {str(e)}'}, status=500)