# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    random_generator.py                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 15:13:42 by bbordere          #+#    #+#              #
#    Updated: 2022/01/06 17:06:34 by bbordere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import random
import sys
int_max = 2147483647
int_min = -2147483648
file = open("rstack.txt", 'w')
t=random.sample(range(-2147483648, 2147483647), int(sys.argv[1]))
for n in t:
	stri = str(n) + " "
	file.write(stri)
file.truncate()
file.close()