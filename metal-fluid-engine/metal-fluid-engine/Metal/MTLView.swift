//
//  MTLView.swift
//  metal-fluid-engine
//
//  Created by Renshi Asada on 2024/10/28.
//

import UIKit
import SwiftUI
import MetalKit


struct MTLView: UIViewControllerRepresentable {
    
    func makeUIViewController(context: Context) -> MTLCanvasViewController {
        return MTLCanvasViewController()
    }
    
    func updateUIViewController(_ uiViewController: MTLCanvasViewController, context: Context) {
        
    }
}
