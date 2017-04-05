//
//  Filter.swift
//  ImageProc
//
//  Created by Arthur Maia Mendes on 26/03/2017.
//  Copyright © 2017 Arthur Maia Mendes. All rights reserved.
//

import Foundation

protocol Filter {
    func apply(input: Image) -> Image
}
