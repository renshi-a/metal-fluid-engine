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
    
    func makeUIViewController(context: Context) -> MTLViewController {
        return MTLViewController()
    }
    
    func updateUIViewController(_ uiViewController: MTLViewController, context: Context) {
        
    }
}

class MTLViewController: UIViewController, MTKViewDelegate {
    
    var renderer: MTLRenderer!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        guard let device = MTLCreateSystemDefaultDevice() else {
            return
        }
        
        let mtkView = MTKView(frame: .zero, device: device)
        mtkView.translatesAutoresizingMaskIntoConstraints = false
        self.view.addSubview(mtkView)
        
        NSLayoutConstraint.activate([
            mtkView.leadingAnchor.constraint(equalTo: self.view.leadingAnchor),
            mtkView.trailingAnchor.constraint(equalTo: self.view.trailingAnchor),
            mtkView.topAnchor.constraint(equalTo: self.view.topAnchor),
            mtkView.bottomAnchor.constraint(equalTo: self.view.bottomAnchor),
        ])
        
        mtkView.delegate = self;
        
        renderer = MTLRenderer(device: device)
    }
    
    func mtkView(_ view: MTKView, drawableSizeWillChange size: CGSize) {}
    
    func draw(in view: MTKView) {
        renderer.draw(mtkView: view)
    }
}

